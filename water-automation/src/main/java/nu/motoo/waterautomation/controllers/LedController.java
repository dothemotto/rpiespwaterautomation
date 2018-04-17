package nu.motoo.waterautomation.controllers;

import com.pi4j.io.gpio.*;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class LedController {

    private static GpioPinDigitalOutput pin;

    @RequestMapping("/light")
    public String lightTheLed() {
        try {
            if (pin == null) {
                GpioController controller = GpioFactory.getInstance();
                pin = controller.provisionDigitalOutputPin(
                        RaspiPin.GPIO_04,
                        "LED",
                        PinState.LOW
                );
            }

            pin.toggle();

            return "LED lighted";
        } catch (Exception e) {
            return "LED cannot be lighted! There are some problems with RPI connection: " + e.getMessage();
        }
    }
}
