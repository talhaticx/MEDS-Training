py:
	clear
	python3 python/sqrt_bs.py

c:
	clear
	rm -f bin/sqrt_bs_C
	gcc C/sqrt_bs.c -o bin/sqrt_bs_C -lm
	./bin/sqrt_bs_C

sv:
	rm -rf obj_dir
	rm -f /bin/sqrt_bs_sv
	verilator -Wall --cc SystemVerilog/sqrt_bs.sv --trace --exe SystemVerilog/testbench.cpp
	make -C obj_dir -j -f Vsqrt_bs.mk Vsqrt_bs
	mv obj_dir/Vsqrt_bs bin/sqrt_bs_sv
	rm -rf obj_dir
	clear
	./bin/sqrt_bs_sv