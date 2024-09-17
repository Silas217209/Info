CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
SRC_DIR := .
BIN_DIR := bin

$(BIN_DIR):
	mkdir -p $@

%: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $< -o $(BIN_DIR)/$@

clean:
	rm -rf $(BIN_DIR)

.PHONY: clean

