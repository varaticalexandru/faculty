package org.alexv.securitytraining.student;

import lombok.*;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class Student {
    private Integer id;
    private String name;
}
