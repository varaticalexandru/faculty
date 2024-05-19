package com.example.demo.config.security;

import com.google.common.net.HttpHeaders;
import io.jsonwebtoken.security.Keys;
import lombok.Data;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.RequiredArgsConstructor;
import org.springframework.boot.context.properties.ConfigurationProperties;

import java.security.Key;
import java.time.LocalDate;
import java.util.Date;

@ConfigurationProperties(prefix = "app.jwt")
@RequiredArgsConstructor
@Data
public class JwtConfig {

    private String tokenPrefix;
    private Integer expirationAfterDays;


    public Date getExpirationDate() {
        return java.sql.Date.valueOf(LocalDate.now().plusDays(expirationAfterDays));
    }

    public String getAuthorizationHeader() {
        return HttpHeaders.AUTHORIZATION;
    }

}
