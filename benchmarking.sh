# for num_y in {8..514..8}
for num_y in 2 4 8 16 32 64 96 128 256 512 1024 2048
do
	for num_x in 2 4 8 16 32 64 96 128 256 512 1024 2048
	# for num_x in {8..514..8}
	do
		sed -i.bak "s/^#define TILE_SIZE_X.*$/#define TILE_SIZE_X ${num_x}/g" kernels.c
		sed -i.bak "s/^#define TILE_SIZE_Y.*$/#define TILE_SIZE_Y ${num_y}/g" kernels.c
		make clean > /dev/null
		make > /dev/null
		OUTPUT="$(./driver_cpe -g)"
		echo "x: ${num_x}; y: ${num_y}"
		echo "${OUTPUT}" | grep "Speedup"
	done
done

