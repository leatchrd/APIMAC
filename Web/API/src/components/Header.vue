// WORK IN PROGRESS

<template>
  <header>
    <h1>{{ title }}</h1>
    <Filter :characters="characters" @filter-change="handleFilterChange" />
  </header>
</template>

<script>
import Filter from './AZFilter.vue';

export default {
  data() {
    return {
      title: "Awesome Disney Characters",
    };
  },
  components: {
    Filter,
  },
  props: {
    characters: {
      type: Array,
    }
  },
  methods: {
    handleFilterChange(filteredCharacters) {
      this.$emit('filter-change', filteredCharacters);
    }
  }
};
</script>

<style scoped>
header {
  background: linear-gradient(to bottom, #83d6c3, #7cacfb);
  color: #fff;
  padding: 10px;
  text-align: center;
  width: 100%;
  /* position: fixed; */
}
</style>