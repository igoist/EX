// 左侧广告
(() => {
  var els = document.querySelectorAll('.j_click_close');

  for (let i = 0; i < els.length; i++) {
    el = els[i];
    el = el.parentNode;
    el.style.display = 'none';
  }
})();

// 动态
// (() => {
//   setTimeout(() => {
//     var els = document.querySelectorAll('.mediago-ad-wrapper');
  
//     for (let i = 0; i < els.length; i++) {
//       el = els[i];
//       console.log('els', i);
//       el.style.display = 'none';
//     }
//   }, 1000);
// })();


const createStyle = (str) => {
  const el = document.createElement('style');
  el.type = 'text/css';
  el.textContent = str;
  document.body.appendChild(el);
};

const str = `
  .mediago-ad-wrapper,
  .right_section,
  .j_click_close {
    display: none!important;
  }
`;

(() => {
  createStyle(str);
})();