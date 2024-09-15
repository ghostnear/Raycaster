TARGET = WebTest

bd:
	@cmake -B build -S . --preset windows-debug
	@cmake --build build

br:
	@cmake -B build -S . --preset windows-release
	@cmake --build build

clean:
	@cmake -E remove_directory build

rd: bd
	@./build/${TARGET}

rr: br
	@./build/${TARGET}