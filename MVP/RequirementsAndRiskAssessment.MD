<h1>REQUIREMENTS AND RISK ASSESSMENT</h1> 

A list of all requirements, both functional and non-functional that have been identified for the project. Additional details surrounding potential risks and risk assessment is also included.

<h2>Requirements</h2>

<h3>Functional Requirements</h3>
All of the requirements of the device which are mandatory for the device to be able to function and serve its purpose when helping visually impaired people. Things like different use scenarios that must be supported will be here.

<h4>User Story One - As a person with visual impairments, I'd like to be able to navigate around my environment so that I can live my life</h4>

LINK 1 -  https://cseejira.essex.ac.uk/browse/D201038-33

<p>The most important issue of them all and whole reason behind this project is to create an alternative to guide dogs using hardware that allows people with visual impairments the ability to go about their daily lives as if their vision was 20/20. The device will need to be able to navigate a person to their destination while avoiding objects and hazards.</p>

Currently, all members of the team are working on this issue as it is the main requirement of the whole project. This issue has not yet been resolved as we are still working towards the first verison of the prototype.

<h4>User Story Two - As an elderly person with visual impairments, I'd like a simple to use device so I can attend my regular appointments</h4>

LINK 2 - https://cseejira.essex.ac.uk/browse/D201038-34

As older people typically suffer more with visual impairments and other things that affect their mobility, the device will need to be able to provide a simple to use interface such as buttons and switches. The device also must be able to move at various speeds as to not overwhelm older people who may prefer to move slower. 

Currently, all of the team project is working on the design but as soon as we have a working prototype, we will develop a lead-like attatchment that can be used to control the devices speed as well as provide real-time feedback to the user. This way, the elderly person can adjust the speed until it is a comfortable walking pace for them.

<h4>User Story Three - As a person who works in a large multi-floor office building, I'd like to be able to use the device in elevators and escalators so I can navigate around the building</h4>

LINK 3 - https://cseejira.essex.ac.uk/browse/D201038-35

<p>The device will need to be able to support and navigate buildings and areas with multiple floors. This includes being able to direct users to the nearest available elevator or other accessible means of moving. This is important as people who need to use public spaces may need to use an alternative to stairs.</p>

The project team currently are not working on resolving this issue however, once a prototype has been delivered and tested, a GPS sensor is to be used in combination with other sensors and software which should allow buildings with multiple floors to be navigated.

<h4>User Story Four - As an active walker, I'd like the device to be robust and weatherproof so that I can use it outside in any wether conditions so I can remain active</h4>

LINK 4 - https://cseejira.essex.ac.uk/browse/D201038-36

An issue has been identified for users who need to use their device in the rain or who are active and do a lot of off-road walking. The internal electronics could become corroded due to exposure to the elements such as water. This could cause a short circuit which can lead to the device breaking down.

Once the prototype has been created and accurate dimensions have been taken of the device's final measurements, a 3D printed case for the device will be created to give it protection from water ingress.


<h4>User Story Five - As someone who lives in a busy city, I'd need the device to be preceptive of hazards such as people, roads and traffic to keep me safe when I can't see </h4>

LINK 5 - https://cseejira.essex.ac.uk/browse/D201038-37

The most important part of our device is the safety of our already vulnerable end users who will rely on our device to get them from A to B safely. Our device must be able to do this while detecting objects, picking up information from the environment such as lights and reflections and avoiding dangers such as traffic, trains and drops.

Currently, our lead programmers and electronics team is working on ensuring that the device has as much visibility and spatial awareness as it can to avoid hazards. Once this is done, further development will continue.

<h3>Non - functional Requirements</h3>
All non-functional requirements such as cosmetic and potentially unecessary needs go here. For examplle, 'I want the device to come in a range of colours' is a non-functional requirement.

<h4>User Story Six - As a person who currently uses a guide dog, I'd like the device to mimic the behaviour and sounds a dog makes so I feel comforted</h4>

LINK 6 - https://cseejira.essex.ac.uk/browse/D201038-38

This isn't really a functional requirement of the device as it does not affect the way it operates. This may be considered as an option in the future if time allows.

Issue is not being worked on.

<h2>Risk Assessment</h2>
All information about potential risks to both the user, other people and the device itself are listed here.

<h4>Risk One - In adverse wether conditions, device's electronics could become damaged leaving the device inoperable and the person stranded.</h4>

LINK 1 - https://cseejira.essex.ac.uk/browse/D201038-43

<p>Some problems have been identified with the device in regards to whether protection from rain and water ingress. This could cause corrosion and shorting of the components which could leave the device inoperable or mean that the device cannot be used in specific wether conditions, greatly limiting its use.</p>

This issue is not currently assigned to any members of the project team and has not yet been addressed.
Actions are going to be taken to address this problem once a working prototype of the device is finalized. From here, we will account for protection from wether in our 3D printed shell design.

<h4>Risk Two - Need to implement a low battery warning to warn the user to charge the device before leaving their current location or home.</h4>

LINK 2 - https://cseejira.essex.ac.uk/browse/D201038-42

<p>The device runs on two sets of batteries which are responsible for powering both the logic and on board devices as well as the two DC motors. If the user were to go on a long journey without charging the device, it could run out of battery, leaving the user stranded.</p>

This issue is again not currently assigned to any team members as we are still focussing on the basic functionality of the device. Once we have a working prototype, smaller issues such as lighting and vibration will be implemeneted.
Actions will be taken and added on to the working prototype such as a red LED that lights up when the battery is less than 30% full or cannot last the lenght of a given journey.

<h4>Risk Three - Due to the nature of HC-SR04 sensors, the device may not notice a ledge and fall off, potentially damaging the device.</h4>

LINK 3 - https://cseejira.essex.ac.uk/browse/D201038-41

<p>The HC-SR04 Sensors work by sending out a signal via the TRIG Pin and wait for a response from the ECHO Pin - this is how the distance is calculated for objects. This however could be a problem as the device may not recognise a steep hill or drop such as a step or kerb. If the device falls, it could become damaged leaving the person stranded.</p>

This issue is currently not being worked on by any of the team members but will be addressed as soon as a working prototype has been created which can move based on sensor input. Once the device can navigate itself, we will test for inclines and declines and add sensors and software tweaks where necessary.


