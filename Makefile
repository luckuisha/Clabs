.PHONY: clean All

All:
	@echo "----------Building project:[ Lab8 - Debug ]----------"
	@cd "Lab8" && "$(MAKE)" -f  "Lab8.mk"
clean:
	@echo "----------Cleaning project:[ Lab8 - Debug ]----------"
	@cd "Lab8" && "$(MAKE)" -f  "Lab8.mk" clean
