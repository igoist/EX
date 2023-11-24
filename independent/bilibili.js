const createStyle = (str) => {
  const el = document.createElement('style');
  el.type = 'text/css';
  el.textContent = str;
  document.body.appendChild(el);
};


// .bili-feed4-layout 首页推荐
// .video-page-game-card-small 详情页右侧，游戏推广

const str = `
  .vcd,
  .video-card-ad-small,
  .video-page-special-card-small,
  .ad-report,
  .slide-ad-exp {
    display: none!important;
  }

  .bili-feed4-layout,
  .video-page-game-card-small,
  .rec-list .video-page-card-small,
  .rec-list .video-page-operator-card-small,
  .next-play .video-page-card-small,
  .part-undefined,
  .pop-live-small-mode {
    opacity: 0!important;
  }

  .next-play .rec-title .next-button .txt,
  .next-play .rec-title {
    color: #fff!important;
  }
`;

(() => {
  createStyle(str);
})();