
#!/bin/bash
for i in {10..200}
do
	echo "Testing: ${i}"
	./tester_2/tester.sh ./ ${i} 5
done