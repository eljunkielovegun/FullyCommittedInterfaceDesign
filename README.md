# FullyCommittedInterfaceDesign
Documentation of the interfaces designed and built for the sound design of Fully Committed at Hartford TheatreWorks, Summer 2019.<br>

<img src="img/Intercom.jpg" width = "300"></img> 
<img src="img/Phone.jpg" width = "300"></img> <br>

<H2>The Set up pf the a remote, two button interface that can be worn and communicates to QLab to control sound cues over wifi through port 53535.</H2>
<br>
<img src="img/Enclosure.jpg" width = "700"></img> <br>
<br>
<img src="img/InsideEnclosure.jpg" width = "700"></img> <br>
<br>
<img src="img/PowerCircuit.jpeg" width = "700"></img> <br>
<br>
<img src="img/Feather.jpeg" width = "700"></img> <br>

<H2>The wired buttons communicates to QLab through MIDI using noteon messages on the notes: 60,70,80</H2><br>
<br>
<img src="img/WiredInterFace.jpg" height = "300"></img> 
<img src="img/TwoButton.jpg" height = "300"></img> 
<img src="img/OneButton.jpg" height ="300"></img> <br>

Right now this requires a Max/MSP patch to be running in the background. You can monitor midi input in the Qlab status window
<br>
 You will need to select the correct serial interface (pull down menu)
<img src="img/SelectSerialPort.png" width ="500"></img> <br>
Double click on the midiout obect to select Qlab
<img src="img/SelectMidiOut.png"  width ="500"></img> <br>


