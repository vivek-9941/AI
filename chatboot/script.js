function sendmessage(){
    let input=  document.getElementById("userinput").value.toLowerCase();
    if(input === "")return ;
    console.log(input)
    let chatbot = document.getElementById("chatbot");
    chatbot.innerHTML += "<div class='user'><b>YOU:</b>"+input+"</div>";
    let reply = "";
    if(input.includes("hi") ||input.includes("hello") ){
        reply = "Hello! Welcome to City Hospital. How can I assist you today?";
    }
    else if(input.includes("appointment")    ){
        reply= "Appointments can be booked from 9 AM to 6 PM.";
    }
    else if(input.includes("doctor")){
        reply = "We have specialists in cardiology, orthopedics, pediatrics, and general medicine.";
    }
   else  if(input.includes("contact")){
        reply = "no .1234567890 . Email: vivekane#@gmsg" ;

    }
    else if(input.includes("timing")){
        reply = "10, to 5pm";
    }
    else reply = "Ask anything about medical , doctor , timing";
    chatbot.innerHTML += "<div class='bot'><b>BOT: "+ reply +"</b></div>";
    document.getElementById("userinput").innerHTML = "";
    chatbot.scrollTop = chatbot.scrollHeight;
}