
#!/bin/bash
for i in {1..500}
do
	echo "Testing: ${i}"
	./tester_2/tester.sh ./ ${i} 3
done