package com.example.demo.service.auth;

import com.example.demo.persistence.dao.AppUserDao;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;


@Service
@RequiredArgsConstructor
public class AppUserService implements UserDetailsService {

    private final AppUserDao appUserDao;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        return appUserDao
                .getAppUser(username)
                .orElseThrow(() -> new UsernameNotFoundException(String.format("Username %s not found.", username)));
    }
}
