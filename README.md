Project Name: lab3-part1
Authors:
NetIDs:
Date:

# Description
For this lab, you will expand on your two-motor lab by changing the control method and displaying the input value on two seven-segment displays. The potentiometer will be replaced with a rotary encoder, whose angular position will control the PWM outputs to the motors. In addition, the angular position of the rotary encoder will be displayed on two seven-segment displays.

## Expected Outcome
The motors should behave as before, but they will now be controlled by a rotary encoder. The angular position of this rotary encoder should be limited to a reasonable range of values requiring two seven-segment displays to show in full. The example from the videos below below uses a range of 0 to 32 so that there is an exact 50% position at 16, but the minutiae of the range you use are up to you.

# Example
<a href="example-videos/example.mp4">Example Video</a>

# Instructions
As before, this lab will require two motors to operate in one of three states: forward, reverse, and idle. The state changes should still be controlled by a button, though the rotary encoder's knob can be pressed to act as such if you wish. To recap, one motor should be at 100% on one half of the input spectrum, linearly decreasing to 0% from the midpoint to the opposite end; the other motor should do the same, but with the input spectrum reversed. That is to say that one motor will be at 100%, the other at 0%, at each end of the input spectrum; which motor is active depends on the end. At the midpoint, they should both be at 100%.

Rotary encoders use discrete changes in rotation to measure their angular positions or changes therein. They come in two varieties, absolute and incremental; an absolute rotary encoder outputs its angular position, while an incremental one outputs changes in its angular position. The rotary encoders in your Arduino kits are incremental.

The seven-segment displays can be controlled in either of two ways: one option is to connect each individual segment to its own pin on the board; the other option is to use shift registers, found in your kits, to reduce pin usage.

# Rubric

<table>
	<tr>
		<th>Lab Participation</th>
		<th>Attended<br />5&nbsp;points</th>
		<th>Not Attended<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>Lab Attendance</td>
		<td>Attended Scheduled Lab Time.</td>
		<td>Did not attend Scheduled Lab Time.</td>
	</tr>
	<tr>
		<th>Demonstration</th>
		<th>Complete<br />15&nbsp;points</th>
		<th>Nearly Complete<br />12&nbsp;points</th>
		<th>Attempted<br />9&nbsp;points</th>
		<th>Minor Attempt<br />3&nbsp;points</th>
		<th>No Attempt<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>
			Demonstration
		</td>
		<td>
			Motor state transitions are smooth.<br /><br />
			Potentiometer is replaced with rotary encoder.<br /><br />
			No Arduino libraries are used.<br /><br />
			Both motors are on at full power when the rotary encoder is in the middle.<br /><br />
			Motors have soldered connections.<br /><br />
			PWM is done using the output-compare modules.<br /><br />
			L293D is used to power the motors.<br /><br />
			Rotary encoder's angular position is represented on two seven-segment displays.
		</td>
		<td>
			No Arduino libraries are used.<br /><br />
			PWM is done using the output-compare modules.<br /><br />
			Potentiometer is replaced with rotary encoder.<br /><br />
			AND 1 of the following is unsatisfied:<br /><br />
			Motor state transitions are smooth.<br /><br />
			Both motors are on at full power when the rotary encoder is in the middle.<br /><br />
			Motors have soldered connections.<br /><br />
			L293D is used to power the motor.<br /><br />
			Rotary encoder's angular position is represented on two seven-segment displays.
		</td>
		<td>
			No Arduino libraries are used.<br /><br />
			PWM is done using the output-compare modules.<br /><br />
			Potentiometer is replaced with rotary encoder.<br /><br />
			AND 2 of the following are unsatisfied:<br /><br />
			Motor state transitions are smooth.<br /><br />
			Both motors are on at full power when the rotary encoder is in the middle.<br /><br />
			Motors have soldered connections.<br /><br />
			L293D is used to power the motor.<br /><br />
			Rotary encoder's angular position is represented on two seven-segment displays.
		</td>
		<td>
			No Arduino libraries are used.<br /><br />
			PWM is done using the output-compare modules.<br /><br />
			Potentiometer is replaced with rotary encoder.<br /><br />
			AND 3 of the following are unsatisfied:<br /><br />
			Motor state transitions are smooth.<br /><br />
			Both motors are on at full power when the rotary encoder is in the middle.<br /><br />
			Motors have soldered connections.<br /><br />
			L293D is used to power the motor.<br /><br />
			Rotary encoder's angular position is represented on two seven-segment displays.
		</td>
		<td>
			No Attempt<br /><br />
			OR<br /><br />
			Arduino libraries are used.<br /><br />
			OR<br /><br />
			PWM is done using the output-compare modules.<br /><br />
			OR<br /><br />
			Potentiometer is not replaced with rotary encoder.
		</td>
	</tr>
	<tr>
		<th>Coding Requirements</th>
		<th>Perfect<br />2.5&nbsp;points</th>
		<th>Lacking<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>State Machine Implementation</td>
		<td>A state machine implementation is used in the while loop of the program.</td>
		<td>Functionality may have been achieved, but no state machine is used.</td>
	</tr>
	<tr>
		<td>States as Enums</td>
		<td>States are not simply done as numbers, but rather as a typedef enum for readability.</td>
		<td>States are done on an integer or some other primitive type, reducing readability.</td>
	</tr>
	<tr>
		<td>Function Decomposition</td>
		<td>Main function does not have multi-line code snippets with direct usage of SFRs.</td>
		<td>Main function has multi-line code snippets with direct usage of SFRs.<br /><br />In other words, instead of a function like initPWM() or turnOnLED(), SFRs are directly manipulated in main.cpp</td>
	</tr>
	<tr>
		<td>Project Structure</td>
		<td>All functions having to do with a particular device are placed in an appropriately named file.<br /><br />LED functions go in led.h, etc.</td>
		<td>Some functions having to do with different devices are grouped together in one file.<br /><br />LED functions are in switch.cpp, etc.</td>
	</tr>
	<tr>
		<th>Git</th>
		<th>Completed<br />6&nbsp;points</th>
		<th>No Attempt<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>Commit History</td>
		<td>Commit to GitLab is created with correct format. When submitting to GitLab "Thanks! Got your submission" is seen.</td>
		<td>No project on GitLab or project has no commits.</td>
	</tr>
	<tr>
		<th>Turn-In Time</th>
		<th>Early<br />15&nbsp;points</th>
		<th>On Time<br />10&nbsp;points</th>
		<th>Late 1 Day<br />5&nbsp;points</th>
		<th>Late 2 Days<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>Turn-In</td>
		<td>Turned in the whole project 1 day early.</td>
		<td>Turned in the whole project on time.</td>
		<td>Turned in the whole project 1 day late.</td>
		<td>Turned in the whole project 2 days late.</td>
	</tr>
	<tr>
		<th>Coding Guidelines</th>
		<th>Perfect<br />1&nbsp;point</th>
		<th>Lacking<br />0&nbsp;points</th>
	</tr>
	<tr>
		<td>Function and Variable Names</td>
		<td>Variable and function names are appropriate.</td>
		<td>A few variable or function names do not make sense or are single letters.</td>
	</tr>
	<tr>
		<td>Function and Variable Names 2</td>
		<td>Variable and function names are in a consistent format.</td>
		<td>A few variable or function names do not have consistent camelCase or snake_case formatting.</td>
	</tr>
	<tr>
		<td>"Magic" Numbers</td>
		<td>"Magic" numbers are defined in #define macros.</td>
		<td>Numbers exist that have no discernible meaning and are not defined in macros.</td>
	</tr>
	<tr>
		<td>Comments</td>
		<td>Comments are included over each function and file.</td>
		<td>Some functions are uncommented and important program logic is not explained.</td>
	</tr>
	<tr>
		<th>Overall Score</th>
		<th>Level 5<br />50&nbsp;or&nbsp;more</th>
		<th>Level 4<br />45&nbsp;or&nbsp;more</th>
		<th>Level 3<br />40&nbsp;or&nbsp;more</th>
		<th>Level 2<br />35&nbsp;or&nbsp;more</th>
		<th>Level 1<br />0&nbsp;or&nbsp;more</th>
	</tr>
</table>