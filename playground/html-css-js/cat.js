document.addEventListener('DOMContentLoaded', function () {
    document.getElementById('cat-photo').onclick = function () {
        document.getElementById('cat-para').innerHTML += ' Meow!';
    }    
});