package com.example.demo.jwt;

import com.example.demo.config.security.JwtConfig;
import com.example.demo.config.security.JwtSecret;
import io.jsonwebtoken.*;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class JwtVerifierFilter extends OncePerRequestFilter {

    private final JwtConfig jwtConfig;
    private final JwtSecret jwtSecret;

    public JwtVerifierFilter(JwtConfig jwtConfig,
                             JwtSecret jwtSecret) {
        this.jwtConfig = jwtConfig;
        this.jwtSecret = jwtSecret;
    }

    @Override
    protected void doFilterInternal(HttpServletRequest request,
                                    HttpServletResponse response,
                                    FilterChain filterChain) throws ServletException, IOException {


        if (request.getHeader(jwtConfig.getAuthorizationHeader()).isBlank()
                || !request.getHeader(jwtConfig.getAuthorizationHeader()).startsWith(jwtConfig.getTokenPrefix())) {
            filterChain.doFilter(request, response);
            return;
        }

        String token = request
                .getHeader(jwtConfig.getAuthorizationHeader())
                .replace(jwtConfig.getTokenPrefix() + " ", "");

        try {
            Jws<Claims> claimsJws = Jwts.parser()
                    .setSigningKey(jwtSecret.getSigningKey())
                    .parseClaimsJws(token);

            Claims body = claimsJws.getBody();
            String username = body.getSubject();

            List<Map<String,String>> authorities = (List<Map<String, String>>) body.get("authorities");

            Set<GrantedAuthority> grantedAuthorities = authorities.stream()
                    .map(authority -> new SimpleGrantedAuthority(authority.get("authority")))
                    .collect(Collectors.toSet());

            Authentication authentication = new UsernamePasswordAuthenticationToken(
                    username,
                    null,
                    grantedAuthorities
            );

            SecurityContextHolder.getContext().setAuthentication(authentication);
        } catch (JwtException e) {
            throw new IllegalStateException(String.format("Token %s can't be trused.", token), e);
        }

        filterChain.doFilter(request, response);
    }
}
