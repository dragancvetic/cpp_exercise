
test2 notes:

The test and verificiataion performed were manual:
	- run application "listFilesDirs -d. -u -s"
	- app. should printout file/folder data
	- compare these data with the outputs from "du -hb". The root directory 
size does not include the root director segment which is usually size of the 
file system block eg. my environment is type ext4 with a block size 4096.  



