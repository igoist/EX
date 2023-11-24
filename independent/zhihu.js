const createStyle = (str) => {
  const el = document.createElement('style');
  el.type = 'text/css';
  el.textContent = str;
  document.body.appendChild(el);
};

const str = `
  .css-1vqda4a {
    display: none!important;
    opacity: 0!important;
  }

  .css-1vqda4a {
    opacity: 0!important;
  }
`;

(() => {
  createStyle(str);

  // 搜索框内鬼东西
  const input = document.querySelector('.SearchBar-input input');
  if (input) {
    input.placeholder = '';
  }
})();