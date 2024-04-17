// EN COURS

<template>
  <div class="character-card">
    <img :src="imageUrl" alt="Character Image" class="character-image" />
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
      required: true,
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
};
</script>

<style scoped>
.character-card {
  /*TO REWORK */
  background: white; /* Couleur des cards */
  width: 200px; /* SÛRE ? */
  border-radius: 10px;
  overflow: hidden; /* SÛRE ? */
  margin: 16px; /* SÛRE ? */
  cursor: pointer;
  transition: transform 0.3s ease;

  padding: 10px; /* SÛRE ? */
}

.character-image {
  /*TO REWORK */
  width: 100%;
  height: 150px;
  object-fit: cover;
}

.card-content {
  padding: 16px;
}

.character-name {
  font-size: 1.2em;
  margin-bottom: 8px;
}

.character-film {
  color: #555;
  margin-bottom: 16px;
}

.character-card {
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