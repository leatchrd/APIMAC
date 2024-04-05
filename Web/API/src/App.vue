<template>
  <div class="dog-card">
    <img class="picture" :src="character.image" />
    <div>
      <h2 class="firstname">{{ character.name }}</h2>
      <p class="breed">{{ character.quote }}</p>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      character: {}
    };
  },
  mounted() {
    this.fetchCharacter();
  },
  methods: {
    fetchCharacter() {
      fetch('https://gravity-falls-api.vercel.app/api/characters/3')
        .then(response => {
          if (!response.ok) {
            throw new Error('Network response was not ok');
          }
          return response.json();
        })
        .then(data => {
          this.character = data;
        })
        .catch(error => {
          console.error('Error fetching character:', error);
        });
    }
  }
};
</script>

<style scoped>
.dog-card {
  border: 1px solid #ccc;
  border-radius: 8px;
  padding: 16px;
  margin-bottom: 16px;
}

.picture {
  width: 100px;
  height: 100px;
  border-radius: 50%;
  object-fit: cover;
  margin-right: 16px;
}

.firstname {
  margin: 0;
}

.breed {
  margin: 0;
  font-style: italic;
  color: #666;
}
</style>
