
#!/bin/bash
# To use this script we need to download this tester https://github.com/louisabricot/push_swap_tester
for i in {1..500}
do
	echo "Testing: ${i}"
	./push_swap_tester/tester.sh ./ ${i} 3
done