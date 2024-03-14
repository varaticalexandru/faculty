package com.example.demo.jwt;

import com.example.demo.api.dto.UserAuthCredentialsDto;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.stereotype.Component;
import org.springframework.security.authentication.AuthenticationManager;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@Component
@RequiredArgsConstructor
public class JwtUsernamePasswordAuthFilter extends UsernamePasswordAuthenticationFilter {


    private final ObjectMapper objectMapper;
    private final AuthenticationManager authenticationManager;

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

        return authenticationManager.authenticate(authentication);
    }
}
