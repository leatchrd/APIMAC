<template>
  <div class="character-card" @click="openCharacterUrl">
    <img :src="getImageUrl()" alt="Character Image" class="character-image" />
    <p>{{ character.name }}</p>
  </div>
</template>

<script>
export default {
  props: {
    character: {
      type: Object,
      required: true
    }
  },
  methods: {
    openCharacterUrl() {
      if (this.character.sourceUrl) {
        window.open(this.character.sourceUrl, '_blank');
      } else {
        this.characterFrison();
      }
    },
    characterFrison() {
      this.$el.classList.add('frison-animation');
      setTimeout(() => {
        this.$el.classList.remove('frison-animation');
      }, 500);
    },
    getImageUrl() {
      return this.character.imageUrl || require('@/assets/unknown.jpg');
    }
  }
};
</script>

<style>
.character-card {
  background-color: white;
  border-radius: 10px;
  padding: 10px;
  text-align: center;
  cursor: pointer;
  transition: transform 0.3s ease;
}

.character-card:hover {
  transform: scale(1.05);
}

.character-image {
  border-radius: 10px;
  width: 150px; 
  height: 150px; 
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
</style>
