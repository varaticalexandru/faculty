package com.example.demo.jwt;

import com.example.demo.api.dto.UserAuthCredentialsDto;
import com.example.demo.config.security.JwtConfig;
import com.example.demo.config.security.JwtSecret;
import com.fasterxml.jackson.databind.ObjectMapper;
import io.jsonwebtoken.Jwts;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.security.authentication.AuthenticationManager;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;


public class JwtAuthFilter extends UsernamePasswordAuthenticationFilter {

    private final ObjectMapper objectMapper;
    private final AuthenticationManager authenticationManager;
    private final JwtConfig jwtConfig;
    private final JwtSecret jwtSecret;

    public JwtAuthFilter(ObjectMapper objectMapper,
                         String SECRET_KEY,
                         AuthenticationManager authenticationManager,
                         JwtConfig jwtConfig,
                         JwtSecret jwtSecret) {
        this.objectMapper = objectMapper;
        this.jwtConfig = jwtConfig;
        this.authenticationManager = authenticationManager;
        this.jwtSecret = jwtSecret;
    }

    @Override
    public Authentication attemptAuthentication(HttpServletRequest request,
                                                HttpServletResponse response) throws AuthenticationException {

        UserAuthCredentialsDto userAuthCredentialsDto;

        try {
            userAuthCredentialsDto = objectMapper.readValue(request.getInputStream(), UserAuthCredentialsDto.class);
        } catch (IOException e) {
            throw new RuntimeException("Exception during request deserialization for JWT parsing.", e);
        }

        Authentication authentication = new UsernamePasswordAuthenticationToken(
                userAuthCredentialsDto.getUsername(),
                userAuthCredentialsDto.getPassword()
        );

        Authentication authResult = authenticationManager.authenticate(authentication);
        return authResult;
    }

    @Override
    protected void successfulAuthentication(HttpServletRequest request,
                                            HttpServletResponse response,
                                            FilterChain chain,
                                            Authentication authResult) throws IOException, ServletException {
        String jwtToken = Jwts.builder()
                .setSubject(authResult.getName())
                .claim("authorities", authResult.getAuthorities())
                .setIssuedAt(new Date())
                .setExpiration(jwtConfig.getExpirationDate())
                .signWith(jwtSecret.getSigningKey())
                .compact();

        response.addHeader(jwtConfig.getAuthorizationHeader(), jwtConfig.getTokenPrefix() + " " + jwtToken);
    }
}
