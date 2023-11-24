const createStyle = (str) => {
  const el = document.createElement('style');
  el.type = 'text/css';
  el.textContent = str;
  document.body.appendChild(el);
};
