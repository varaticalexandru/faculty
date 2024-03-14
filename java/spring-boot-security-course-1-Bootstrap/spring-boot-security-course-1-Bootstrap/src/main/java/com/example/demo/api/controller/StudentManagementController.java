package com.example.demo.api.controller;

import com.example.demo.model.Student;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;


import java.util.*;

@RestController
@RequestMapping("/management/api/v1/students")
public class StudentManagementController {

    private static final List<Student> STUDENTS = new ArrayList<>(
            List.of(
                    Student.builder().id(1).name("John").build(),
                    Student.builder().id(2).name("Mary").build(),
                    Student.builder().id(3).name("Daniel").build()
            )
    );


    @GetMapping()
    @PreAuthorize(
            "hasAnyRole('ADMIN', 'ADMIN_TRAINEE') and " +
                    "hasAnyAuthority('student:read')"
    )
    public List<Student> getAllStudents() {
        return STUDENTS;
    }

    @GetMapping("/{studentId}")
    @PreAuthorize(
            "hasAnyRole('ADMIN', 'ADMIN_TRAINEE') and " +
                    "hasAuthority('student:read')"
    )
    public Student getStudent(@PathVariable Integer studentId) {
        return STUDENTS
                .stream()
                .filter(student -> student.getId().equals(studentId))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException(String.format("Student %s does not exist.", studentId)));
    }

    @PostMapping
    @PreAuthorize(
            "hasAnyRole('ADMIN', 'ADMIN_TRAINEE') and " +
                    "hasAuthority('student:write')"
    )
    public boolean registerStudent(@RequestBody Student student) {
        return STUDENTS.add(student);
    }

    @PutMapping("/{studentId}")
    @PreAuthorize(
            "hasAnyRole('ADMIN', 'ADMIN_TRAINEE') and " +
            "hasAuthority('student:write')"
    )
    public Student updateStudent(
            @PathVariable("studentId") Integer studentId,
            @RequestBody Student student
    ) {

        Student updatedStudent = STUDENTS.stream()
                .filter(s -> s.getId().equals(studentId))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException(String.format("Student %s does not exist.", studentId)));

        updatedStudent.setName(student.getName());

        return updatedStudent;
    }

    @DeleteMapping("/{studentId}")
    @PreAuthorize(
            "hasAnyRole('ADMIN', 'ADMIN_TRAINEE') and " +
            "hasAuthority('student:write')"
    )
    public boolean deleteStudent(@PathVariable("studentId") Integer studentId) {
        return STUDENTS.remove(
                STUDENTS
                        .stream()
                        .filter(student -> student.getId().equals(studentId))
                        .findFirst()
                        .orElse(new Student())
        );

    }

}
