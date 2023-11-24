// 首页推荐
(() => {
  var els = document.querySelectorAll('#s_main');

  for (let i = 0; i < els.length; i++) {
    el = els[i];
    el = el.parentNode;
    el.style.display = 'none';
  }
})();
