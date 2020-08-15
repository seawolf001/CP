
select P.FirstName, P.LastName, A.City, A.State
from Person P inner join Address A
where P.PersonId == A.PersonId;
