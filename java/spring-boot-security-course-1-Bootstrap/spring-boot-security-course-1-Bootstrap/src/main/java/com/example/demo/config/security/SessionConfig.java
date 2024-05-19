package com.example.demo.config.security;

import lombok.Data;
import lombok.RequiredArgsConstructor;
import org.springframework.boot.context.properties.ConfigurationProperties;

@ConfigurationProperties("app.session.remember-me")
@RequiredArgsConstructor
@Data
public class SessionConfig {

    private String secretKey;
}
