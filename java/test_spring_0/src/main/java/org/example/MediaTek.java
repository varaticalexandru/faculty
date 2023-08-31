package org.example;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;

@Component
public class MediaTek implements MobileProcessor {


    @Override
    public void process() {
        System.out.println("2nd best cpu");
    }
}
