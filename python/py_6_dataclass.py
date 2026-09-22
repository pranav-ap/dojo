from dataclasses import dataclass, field


@dataclass(frozen=True)
class Coordinate:
    lat: float
    lon: float

    """
    The default_factory parameter lets you provide a function, class, or any other call
    able, which will be invoked with zero arguments to build a default value each time an
    instance of the data class is created.
    """
    guests: list[str] = field(default_factory=list)

    """
    do extra setup or validation that needs the fields to already exist
    """
    def __post_init__(self):
        # validation
        if not -90 <= self.lat <= 90:
            raise ValueError("lat out of range")

        if not -180 <= self.lon <= 180:
            raise ValueError("lon out of range")

        # derived field
        # self.label = f"{self.lat:.2f}, {self.lon:.2f}"

    def __str__(self):
        return f'{(self.lat, self.lon)}'
