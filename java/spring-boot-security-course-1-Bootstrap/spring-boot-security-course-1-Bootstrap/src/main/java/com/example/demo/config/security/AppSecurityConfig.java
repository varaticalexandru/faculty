package com.example.demo.config.security;

import com.example.demo.model.AppUserRole;
import com.example.demo.service.auth.AppUserService;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpMethod;
import org.springframework.security.authentication.dao.DaoAuthenticationProvider;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.util.matcher.AntPathRequestMatcher;

import java.util.concurrent.TimeUnit;

@Configuration
@EnableWebSecurity
@EnableGlobalMethodSecurity(prePostEnabled = true)
@RequiredArgsConstructor
public class AppSecurityConfig extends WebSecurityConfigurerAdapter {

    private final PasswordEncoder passwordEncoder;
    private final AppUserService appUserService;


    @Override
    protected void configure(HttpSecurity http) throws Exception {

        http
//                .csrf().csrfTokenRepository(CookieCsrfTokenRepository.withHttpOnlyFalse()).and()
                .csrf().disable()
                .authorizeRequests()
                .antMatchers(HttpMethod.GET, "/test").permitAll()
                .antMatchers("/api/v1/students/**").hasRole(AppUserRole.STUDENT.name())
                    // for an exact endpoint either role- or authority-level access control (the last rule will overwrite all precedent ones)
//                .antMatchers("/management/api/**").hasAnyAuthority(
//                        ObjectArrays.concat(
//                                ADMIN.getGrantedAuthoritiesArr(),
//                                ADMIN_TRAINEE.getGrantedAuthoritiesArr(),
//                                String.class
//                        )
//                )
//                .antMatchers(HttpMethod.GET, "/management/api/v1/students/**").hasAuthority(STUDENT_READ.getUserAuthority())
//                .antMatchers(HttpMethod.POST, "/management/api/v1/students/**").hasAuthority(STUDENT_WRITE.getUserAuthority())
//                .antMatchers(HttpMethod.PUT, "/management/api/v1/students/**").hasAuthority(STUDENT_WRITE.getUserAuthority())
//                .antMatchers(HttpMethod.DELETE, "/management/api/v1/students/**").hasAuthority(STUDENT_WRITE.getUserAuthority())
                .anyRequest()
                .authenticated()
                .and()
                .formLogin()
                    .loginPage("/login").permitAll()
                    .defaultSuccessUrl("/courses", true)
                    .usernameParameter("username")
                    .passwordParameter("password")
                .and()
                .rememberMe()
                    .tokenValiditySeconds((int) TimeUnit.DAYS.toSeconds(21))
                    .key("somethingverysecure")
                    .rememberMeParameter("remember-me")
                .and()
                .logout()
                    .logoutUrl("/logout")
                    .logoutRequestMatcher(new AntPathRequestMatcher("/logout", "GET"))
                    .clearAuthentication(true)
                    .invalidateHttpSession(true)
                    .deleteCookies("JSESSIONID", "remember-me")
                    .logoutSuccessUrl("/login");
    }

    @Bean
    public DaoAuthenticationProvider daoAuthenticationProvider() {

        DaoAuthenticationProvider daoAuthenticationProvider = new DaoAuthenticationProvider();
        daoAuthenticationProvider.setPasswordEncoder(passwordEncoder);
        daoAuthenticationProvider.setUserDetailsService(appUserService);

        return daoAuthenticationProvider;
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.authenticationProvider(daoAuthenticationProvider());
    }

    //    @Override
//    @Bean
//    protected UserDetailsService userDetailsService() {
//
//        UserDetails userDetails1 = User.builder()
//                .username("Mary")
//                .password(passwordEncoder.encode("Mary123"))
//                .roles(AppUserRole.STUDENT.name())
//                .build();
//
//        UserDetails userDetails2 = User.builder()
//                .username("John")
//                .password(passwordEncoder.encode("John123"))
//                .roles(AppUserRole.ADMIN.name())
//                .build();
//
//        UserDetails userDetails3 = User.builder()
//                .username("Linda")
//                .password(passwordEncoder.encode("Linda123"))
//                .roles(AppUserRole.ADMIN.name())
//                .authorities(AppUserRole.ADMIN.getGrantedAuthorities())
//                .build();
//
//        UserDetails userDetails4 = User.builder()
//                .username("Tom")
//                .password(passwordEncoder.encode("Tom123"))
//                .roles(AppUserRole.ADMIN_TRAINEE.name())
//                .authorities(AppUserRole.ADMIN_TRAINEE.getGrantedAuthorities())
//                .build();
//
//
//        return new InMemoryUserDetailsManager(
//                userDetails1,
//                userDetails2,
//                userDetails3,
//                userDetails4
//        );
//    }
}
