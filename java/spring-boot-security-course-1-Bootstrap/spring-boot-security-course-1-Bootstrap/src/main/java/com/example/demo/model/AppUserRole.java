package com.example.demo.model;

import com.google.common.collect.Sets;
import lombok.Getter;
import lombok.RequiredArgsConstructor;
import org.springframework.security.core.authority.SimpleGrantedAuthority;

import java.util.Collection;
import java.util.Set;
import java.util.stream.Collectors;

@Getter
@RequiredArgsConstructor
public enum AppUserRole {


    ADMIN(Sets.newHashSet(AppUserAuthority.STUDENT_READ, AppUserAuthority.STUDENT_WRITE, AppUserAuthority.COURSE_READ, AppUserAuthority.COURSE_WRITE)),
    ADMIN_TRAINEE(Sets.newHashSet(AppUserAuthority.STUDENT_READ)),
    STUDENT(Sets.newHashSet());

    private final Set<AppUserAuthority> userAuthoritySet;


    public Collection<SimpleGrantedAuthority> getGrantedAuthorities() {

        Set<SimpleGrantedAuthority> grantedAuthorities = getUserAuthoritySet()
                .stream()
                .map(appUserAuthority -> new SimpleGrantedAuthority(appUserAuthority.getUserAuthority()))
                .collect(Collectors.toSet());

        grantedAuthorities.add(new SimpleGrantedAuthority("ROLE_" + this.name()));

        return grantedAuthorities;
    }

    public String[] getGrantedAuthoritiesArr() {
        String[] grantedAuthorities = getUserAuthoritySet()
                .stream()
                .map(AppUserAuthority::getUserAuthority)
                .toArray(String[]::new);

        String[] newGrantedAuthorities = new String[grantedAuthorities.length + 1];

        System.arraycopy(grantedAuthorities, 0, newGrantedAuthorities, 0, grantedAuthorities.length);
        newGrantedAuthorities[grantedAuthorities.length + 1] = "ROLE_" + this.name();

        return newGrantedAuthorities;
    }
}
