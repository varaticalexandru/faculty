package org.alexv.securitytraining.student;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;

@RestController
@RequestMapping("/api/students")
public class StudentController {

    private static final List<Student> STUDENTS = Arrays.asList(
            Student.builder().id(1).name("John").build(),
            Student.builder().id(2).name("Mary").build(),
            Student.builder().id(3).name("Daniel").build()
    );

    @GetMapping("/{studentId}")
    public Student getStudent(@PathVariable("studentId") Integer studentId) {
        return STUDENTS
                .stream()
                .filter(student -> student.getId().equals(studentId))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException(String.format("Student %s does not exist.", studentId)));
    }


}
