package nu.motoo.waterautomation.services;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.atomic.AtomicBoolean;

@Service
public class WateringService {
    private static final Logger logger = LoggerFactory.getLogger(WateringService.class);
    private static final DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("HH:mm:ss");
    private final AtomicBoolean enabled = new AtomicBoolean(false);

    @Scheduled(cron = "*/10 * * * * ?", zone="Europe/Bucharest")
    public void execute() {
        if (enabled.get()) {
            //TODO call the query service
            logger.info("Cron Task :: Execution Time - {}", dateTimeFormatter.format(LocalDateTime.now()));
        }
    }

    public void start() {
        enabled.set(true);
    }

    public void stop() {
        enabled.set(false);
    }
}
