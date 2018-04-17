package nu.motoo.waterautomation;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication
@EnableAutoConfiguration
@ComponentScan(basePackages = "nu.motoo.waterautomation")
@EnableScheduling
public class WaterAutomationApplication {

	public static void main(String[] args) {
		SpringApplication.run(WaterAutomationApplication.class, args);
	}
}
