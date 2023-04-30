function myFunction() {
    var x = document.getElementById("myTopnav");
    if (x.className === "topnav") {
        x.className += " responsive";
    } else {
        x.className = "topnav";
    }
}

window.onscroll = function() {
    var theta = document.documentElement.scrollTop / 50 % Math.PI;

    document.getElementById('js-logo').style.transform = 'rotate(' + theta + 'rad)';
}

$(function() {
    $(document).scroll(function() {
        var $nav = $(".navbar-fixed-top");
        $nav.toggleClass('scrolled', $(this).scrollTop() > $nav.height());
    });
});

/* Menu js */
var btn = document.getElementById('btn');

btn.addEventListener('click', function() {
    document.body.classList.toggle('red');
}, false);