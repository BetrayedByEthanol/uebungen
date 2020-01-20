var divs = ["Div1", "Div2", "Div3", "Div4"];
var visibleDivId = null;
const http = new XMLHttpRequest;
http.onload = whenLoaded;

window.onload = function() {
  document.getElementById(divId).style.display = 'none';
};


function toggleVisibility(divId) {
  if(visibleDivId === divId) {
    //visibleDivId = null;
  } else {
    visibleDivId = divId;
  }
  
  hideNonVisibleDivs();
}

function hideNonVisibleDivs() {
  var i, divId, div;
  for(i = 0; i < divs.length; i++) {
    divId = divs[i];
    div = document.getElementById(divId);
    if (div.style.display == "none") {
      if(visibleDivId === divId) {
        div.style.display = "block";
      } else {
        div.style.display = "none";
      }
    } else {
      div.style.display = "none"
    } 
  }
}



// setTimeout(function blah() {
//   document.getElementById("transition").style.display = "none" 
//   document.getElementById("transition").style.transition = "all 2s";
// }, 3000);

