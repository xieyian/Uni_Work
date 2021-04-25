SELECT film.title from film where film.film_id NOT IN(select distinct inventory.film_id from inventory);
