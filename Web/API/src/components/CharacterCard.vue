
<template>
  <div class="character-card" @click="openCharacterUrl">
    <div class="image-container">
      <img :src="getImageUrl()" alt="Character Image" class="character-image" />
    </div>
    <p>{{ character.name }}</p>
  </div>
</template>

<script>
export default {
  props: {
    character: {
      type: Object,
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
      return this.character.imageUrl || require("@/assets/unknown.jpg");
    },
  },
};
</script>

<style>
.character-card {
  background: white; /* Couleur des cards */
  border-radius: 10px;
  padding: 10px;
  font-family: Arial, Helvetica, sans-serif;
  text-align: center;
  cursor: pointer;
  transition: transform 0.3s ease;
}

.character-card:hover {
  transform: scale(1.09);
}

.image-container {
  width: 100%;
  height: 150px;
  overflow: hidden;
}

.character-image {
  width: 100%;
  height: 150px;
  border-radius: 10px;
  object-fit: cover;
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
