package com.example.demo.persistence.dao.impl;

import com.example.demo.model.auth.AppUser;
import com.example.demo.persistence.dao.AppUserDao;
import lombok.RequiredArgsConstructor;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.Optional;
import java.util.Set;

import static com.example.demo.model.AppUserRole.*;

@Repository("fakeAppUserDao")
@RequiredArgsConstructor
public class AppUserDaoImpl implements AppUserDao {

    private final PasswordEncoder passwordEncoder;

    @Override
    public Optional<UserDetails> getAppUser(String username) {

        return getAllAppUsers()
                .stream()
                .filter(appUser -> appUser.getUsername().equals(username))
                .findFirst();
    }

    public Collection<UserDetails> getAllAppUsers() {
        return Set.of(
                AppUser.builder()
                        .username("John")
                        .password(passwordEncoder.encode("John123"))
                        .grantedAuthorities(ADMIN.getGrantedAuthorities())
                        .isAccountNonExpired(true)
                        .isEnabled(true)
                        .isAccountNonLocked(true)
                        .isCredentialsNonExpired(true)
                        .build(),

                AppUser.builder()
                        .username("Mary")
                        .password(passwordEncoder.encode("Mary123"))
                        .grantedAuthorities(STUDENT.getGrantedAuthorities())
                        .isAccountNonExpired(true)
                        .isEnabled(true)
                        .isAccountNonLocked(true)
                        .isCredentialsNonExpired(true)
                        .build(),

                AppUser.builder()
                        .username("Tom")
                        .password(passwordEncoder.encode("Tom123"))
                        .grantedAuthorities(ADMIN_TRAINEE.getGrantedAuthorities())
                        .isAccountNonExpired(true)
                        .isEnabled(true)
                        .isAccountNonLocked(true)
                        .isCredentialsNonExpired(true)
                        .build(),

                AppUser.builder()
                        .username("Linda")
                        .password(passwordEncoder.encode("Linda123"))
                        .grantedAuthorities(ADMIN.getGrantedAuthorities())
                        .isAccountNonExpired(true)
                        .isEnabled(true)
                        .isAccountNonLocked(true)
                        .isCredentialsNonExpired(true)
                        .build()
        );
    }
}
