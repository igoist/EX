const createStyle = (str) => {
  const el = document.createElement('style');
  el.type = 'text/css';
  el.textContent = str;
  document.body.appendChild(el);
};

const str = `
  .ytd-action-companion-ad-renderer {
    display: none!important;
  }

  .ytd-action-companion-ad-renderer {
    opacity: 0;
  }
`;

(() => {
  createStyle(str);
})();