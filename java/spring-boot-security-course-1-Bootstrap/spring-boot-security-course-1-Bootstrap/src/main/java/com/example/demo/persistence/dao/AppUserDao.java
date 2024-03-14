package com.example.demo.persistence.dao;

import org.springframework.security.core.userdetails.UserDetails;

import java.util.Optional;

public interface AppUserDao {
    Optional<UserDetails> getAppUser(String username);
}
