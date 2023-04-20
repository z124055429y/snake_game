(*

This Apple script will resize any program window to an exact size and the window is then moved to the center of your screen.
Specify the program name, height and width below and run the script.

Written by Amit Agarwal on December 10, 2013

*)

set theApp to "Terminal"
set appHeight to 600
set appWidth to 1000

tell application "Finder"
	set screenResolution to bounds of window of desktop
end tell

set screenWidth to item 3 of screenResolution
set screenHeight to item 4 of screenResolution

tell application theApp
	activate
	reopen
	set yAxis to (screenHeight - appHeight) / 2 as integer
	set xAxis to (screenWidth - appWidth) / 2 as integer
	set the bounds of the first window to {xAxis, yAxis, appWidth + xAxis, appHeight + yAxis}
end tell
