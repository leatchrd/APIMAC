// WORK IN PROGRESS

<template>
  <div class="character-card" @click="openCharacterUrl">
    <img class="character-image" :src="getImageUrl()" alt="Character Image" />
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
      default: "./assets/unknown.jpg",
    },
    name: {
      type: String,
      required: true,
    },
    films: {
      type: Array,
      required: true,
    },
    _id: {
      type: String,
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
  background: white;
  width: 200px;
  border-radius: 10px;
  overflow: hidden;
  margin: 16px;
  cursor: pointer;
  transition: transform 0.3s ease;
  padding: 10px;
}

.character-card:hover {
  transform: scale(1.09);
}

.character-image {
  width: 100%;
  height: 150px;
  border-radius: 10px;
  object-fit: cover;
  margin-bottom: 10px;
}

.card-content {
  padding: 20px;
}

.character-name {
  font-size: 1.5em;
  margin-bottom: 10px;
}

.character-film {
  font-size: 1.5em;
  margin-bottom: 10px;
}

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