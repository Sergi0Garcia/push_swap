
#!/bin/bash
for i in {80..130}
do
	echo "Testing: ${i}"
	./tester_2/tester.sh ./ ${i} 5
done