package nu.motoo.waterautomation.controllers;

import nu.motoo.waterautomation.services.WateringService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;

@RestController
public class WateringController {
    private static final Logger logger = LoggerFactory.getLogger(WateringController.class);

    @Autowired
    WateringService wateringService;


    @RequestMapping("/start")
    public String start(HttpServletRequest request) {
        wateringService.start();
        logger.info("Task has been started by " + request.getRemoteAddr());
        return "Task started!";
    }

    @RequestMapping("/stop")
    public String stop(HttpServletRequest request) {
        wateringService.stop();
        logger.info("Task has been stopped by " + request.getRemoteAddr());
        return "Task stopped!";
    }
}
