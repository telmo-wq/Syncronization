CFLAGS = -Wall -pthread

sync_car: src/sync_car.c src/sync_car-runner.c 
	gcc $(CFLAGS) -o sync_car src/sync_car.c src/sync_car-runner.c 


clean: 
	rm -rf sync_car