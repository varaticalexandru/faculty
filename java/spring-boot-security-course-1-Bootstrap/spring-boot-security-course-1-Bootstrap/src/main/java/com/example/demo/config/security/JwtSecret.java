package com.example.demo.config.security;

import io.jsonwebtoken.security.Keys;
import lombok.Data;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.RequiredArgsConstructor;
import org.springframework.boot.context.properties.ConfigurationProperties;

import java.security.Key;

@ConfigurationProperties(prefix = "app.jwt.secret")
@RequiredArgsConstructor
@Data
public class JwtSecret {

    private String key;

    public Key getSigningKey() {
        return Keys.hmacShaKeyFor(key.getBytes());
    }
}
