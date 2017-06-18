.PHONY: clean All

All:
	@echo "----------Building project:[ Game_of_Life - Debug ]----------"
	@cd "Game_of_Life" && "$(MAKE)" -f  "Game_of_Life.mk"
clean:
	@echo "----------Cleaning project:[ Game_of_Life - Debug ]----------"
	@cd "Game_of_Life" && "$(MAKE)" -f  "Game_of_Life.mk" clean
