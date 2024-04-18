// EN COURS, FINAL
// PAS SÛRE DU getImageUrl()
<template>
  <div class="character-card" @click="openCharacterUrl">
    <img :src="getImageUrl()" alt="Character Image" class="character-image" />
    <div class="card-content">
      <h3 class="character-name">{{ name }}</h3>
      <p class="character-film">{{ films }}</p>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    imageUrl: {
      type: String,
      default : './assets/unknown.jpg',
    //  required: true,
    },
    name: {
      type: String,
      required: true,
    },
    films: {
      type: String,
      required: true,
    },
    _id: {
      type: Number,
      required: true,
    },
  },

  methods: {
    openCharacterUrl() {
      if (this.character.sourceUrl) {
        window.open(this.character.sourceUrl, "_blank");
      } else {
        this.characterFrison();
      }
    },
    characterFrison() {
      this.$el.classList.add("frison-animation");
      setTimeout(() => {
        this.$el.classList.remove("frison-animation");
      }, 500);
    },
    getImageUrl() {
      return this.character.imageUrl;
    },
  },
};
</script>

<style scoped>
.character-card {
  /*TO REWORK */
  background: white;
  /* Couleur des cards */
  width: 200px;
  /* SÛRE ? */
  border-radius: 10px;
  overflow: hidden;
  /* SÛRE ? */
  margin: 16px;
  /* SÛRE ? */
  cursor: pointer;
  transition: transform 0.3s ease;

  padding: 10px;
  /* L SÛRE ? */
}

.character-card:hover {
  transform: scale(1.09);
}

.character-image {
  width: 100%;
  height: 150px;
  border-radius: 10px;
  /* L SÛRE ? */
  object-fit: cover;
  margin-bottom: 10px;
  /* L SÛRE ? */
}

.card-content {
  padding: 20px;
  /* SÛRE ? */
}

.character-name {
  font-size: 1.5em;
  /* SÛRE ? */
  margin-bottom: 10px;
  /* SÛRE ? */
}

.character-film {
  color: #555;
  /* SÛRE ? */
  margin-bottom: 10px;
}

/* ------ L SÛRE ? ------ */
.frison-animation {
  animation: frison 0.5s ease;
}

@keyframes frison {
  0% {
    transform: translateX(-5px);
  }

  50% {
    transform: translateX(5px);
  }

  100% {
    transform: translateX(-5px);
  }
}

@media screen and (min-width: 768px) {
  .character-card {
    padding: 20px;
  }
}
</style>