package com.example.demo.model;

import lombok.Getter;
import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
@Getter
public enum AppUserAuthority {

    STUDENT_READ("student:read"),
    STUDENT_WRITE("student:write"),

    COURSE_READ("course:read"),
    COURSE_WRITE("course:write");

    private final String userAuthority;
}
