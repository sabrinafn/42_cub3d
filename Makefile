SERVICE = mlxgame

build:
	@echo "Building the Docker image for $(SERVICE)..."
	@docker compose build $(SERVICE) > /dev/null 2>&1
	@echo "Docker image built successfully."

run:
	@echo "Starting the container in the background..."
	@docker compose up -d $(SERVICE) > /dev/null 2>&1
	@echo "Container is now running."

map:
ifndef MAP
	@echo "Error: you must provide a map file."
	@echo "Example: make map MAP=maps_valid/brick_wall.cub"
	@exit 1
endif
	@echo "Running cub3D with map: $(MAP)..."
	docker compose exec $(SERVICE) ./cub3D assets/$(MAP)
	@echo "Game execution finished."

clean:
	@echo "Stopping and removing containers, images, and volumes..."
	@docker compose down --rmi all -v --remove-orphans > /dev/null 2>&1
	@echo "Clean up completed."

help:
	@echo ""
	@echo "Available commands:"
	@echo "  make build          -> build the Docker image"
	@echo "  make run            -> start the container in background"
	@echo "  make map MAP=map    -> run the game with the chosen map"
	@echo "                         ex.: make map MAP=maps_valid/brick_wall.cub"
	@echo "  make clean          -> remove containers/images/volumes"
	@echo "  make help           -> show this help"
	@echo ""
	@echo "Available VALID maps:"
	@ls app/assets/maps_valid | sed 's/^/   - /'
	@echo ""
	@echo "Available INVALID maps:"
	@ls app/assets/maps_invalid | sed 's/^/   - /'
	@echo ""
	@echo "Recommended workflow to avoid initial delay:"
	@echo "  Step 1 - Build the Docker image (only once):"
	@echo "      > make build"
	@echo "  Step 2 - Start the container in background (only once):"
	@echo "      > make run"
	@echo "  Step 3 - Run the game with a map:"
	@echo "      > make map MAP=maps_valid/brick_wall.cub"
	@echo ""
